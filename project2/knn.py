import numpy as np
import json 
from sklearn.neighbors import KNeighborsClassifier

class KNN:
    def __init__(self, k): 
        self.k = k

    # k-means를 통해 얻은 k개의 rgb 값에서 제일 많은 영역인 흰 바탕을 제외한 k-1개의 rgb값들 중
    # 각각의 rgb 값에 대한 color.json과의 knn알고리즘 적용 함수
    def knn_Color(self, rgb_data, k):
        # color.json 불러오기
        with open('color.json', 'r') as f:
            color_data = json.load(f)

        # dataset에는 약 600개의 3크기의 rgb 값 리스트 불러오기
        # target에는 dataset에 해당하는 rgb 값의 target label(20개의 label 존재)
        dataset = np.array(color_data['color'])
        target = np.array(color_data['target'])
        
        # KNeighborsClassifier를 이용하여 dataset과 target을 fit시킴
        clf = KNeighborsClassifier(n_neighbors=k, weights='distance')
        clf.fit(dataset, target)

        # result 배열에 predict함수를 이용하여 각 rgb 데이터에 해당하는 예측된 색깔 label 넣기
        # ex) '스카이블루' , '블랙'
        result = []
        for rgb in rgb_data :
            predict_Color = clf.predict(np.array([rgb]))
            result.append(predict_Color[0])

        return result