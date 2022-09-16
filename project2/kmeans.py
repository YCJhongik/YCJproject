import numpy as np
import cv2
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

class KMEANS:
    def __init__(self, k): 
        self.k = k

    # 
    def plot_colors(self, hist, centroids):
        bar = np.zeros((50, 300, 3), dtype="uint8")
        startX = 0

        for (percent, color) in zip(hist, centroids):
            endX = startX + (percent * 300)
            cv2.rectangle(bar, (int(startX), 0), (int(endX), 50), color.astype("uint8").tolist(), -1)
            startX = endX

        return bar

    # K-means 알고리즘을 이용한 후 얻은 군집을 histogram 함수를 이용하여 k개의 군집 비율 측정 함수
    def centroid_rate(self, cluster):
        # histogram 함수를 이용하기 위해 
        # numLabels는 histogram의 간격을 설정하기 위해 총 rgb 군집의 labels_ 개수 만큼의 간격 설정
        # histogram 함수를 통해 cluster된 군집들의 RGB 비율을 만들어 낸다.
        numLabels = np.arange(0, len(np.unique(cluster.labels_)) + 1)
        rate, bins = np.histogram(cluster.labels_, numLabels)
        
        # 전체 비율들의 합으로 나눠줌으로써 rate에는 전체 cluster 된 군집들의 분포를 총합 1이 되게끔 저장
        rate = rate.astype("float")
        rate /= rate.sum()

        return rate

    # K-means를 이용한 RGB 군집 분류 함수
    def rgbData(self, image, k) :
        # image의 BGR 3채널을 RGB 형식을 수정
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        # image의 width * height를 1차원으로 reshape하여 계산 수월하게 적용
        image = image.reshape((image.shape[0] * image.shape[1], 3))

        # RGBcluster에 KMeans 라이브러리 사용하여 군집 형성
        RGBcluster = KMeans(n_clusters = k)
        RGBcluster.fit(image)

        # RGBcluster에 담긴 RGB 데이터 군집들의 분포를 측정
        rate = self.centroid_rate(RGBcluster)

        # k개의 RGB 데이터 
        RGBdata = np.empty((0,4))
        for i in range(k - 1) :
            # rate에서 가장 큰 값의 인덱스의 다음(제일 큰 것은 흰 배경이기 때문에 건너뜀)부터 index를 설정
            index = np.argsort(rate)[-2-i]

            # RGB 값과 그 RGB 값의 비율을 하나의 numpy 배열로 반환하기 위해 center_RGB numpy 배열 선언
            center_RGB = np.array([])

            # center_RGB에는 cluster된 군집의 cenroid 값 RGB와 그 RGB가 전체 중 어느 정도의 비율을 차지하는지 4 크기의 리스트로 붙여서 넣어줌
            # center_RGB는 2차원 배열로 각 요소는 4 크기의 RGB값 + RGB비율로 되어있음
            # 소숫점 둘째 자리까지 버림을 해서 적용함
            center_RGB = np.append(center_RGB, np.floor(RGBcluster.cluster_centers_[index]*100)/100)
            center_RGB = np.append(center_RGB, np.floor(rate[index]*1000)/100)
            RGBdata = np.append(RGBdata, np.array([center_RGB]), axis=0)

        return RGBdata