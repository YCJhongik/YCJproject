import numpy as np
import glob 
import cv2
import json 
from PIL import Image
import random
from knn import KNN
from kmeans import KMEANS

# 스타일 입력받기
print()
print("----------------------------------------------------------")
print("스타일 | 로맨틱 모던 섹시 스트리트 스포티 클래식 페미닌")
print("----------------------------------------------------------")
print()
style = input("원하는 스타일을 골라주세요 : ")

# input으로 넣을 상품 사진 json load 하기
with open('product_label/clothes (97).json', 'r') as f:
    json_data = json.load(f)

# 상품 사진이 아우터, 상의, 하의 중 무엇인지 확인
category_id = json_data['category_id']

if category_id == 1 :
    category_id = '아우터'
elif category_id == 2 :
    category_id = '상의'
else :
    category_id = '하의'

path = 'product_image/clothes (97).jpg'
image = cv2.imread(path, cv2.IMREAD_COLOR)

# Kmeans를 통한 cluster된 군집 중앙의 rgb 값과 비율 구하기
k = 5
k_M = KMEANS(k)
rgb_data = k_M.rgbData(image, k)
cluster_rgb = np.empty((0,3))
rate = np.empty((0,3))
for i in range(len(rgb_data)):
    cluster_rgb = np.append(cluster_rgb, np.array([rgb_data[i][0:3]]), axis=0)
    rate = np.append(rate, rgb_data[i][3])

# KNN을 이용하여 rgb 값과 color.json을 비교한 target color 구하기
# knn_Color함수 호출하여 사용
k = 5
kN = KNN(k)
print(cluster_rgb)
print(rate)
result = kN.knn_Color(cluster_rgb, k)

# rate들에 해당하는 color들 중 가장 많은 비율을 차지하는 color가 무엇인지 딕셔너리를 이용
# 딕셔너리에 넣어둔 데이터를 통해 value가 가장 높은 color를 target으로 설정함
color_class = {}
for i in range(len(result)):
    if color_class.get(result[i]) == None :
        color_class[result[i]] = rate[i]
    else :
        color_class[result[i]] += rate[i]

# 딕셔너리를 확인한 후 이 딕셔너리에서 가장 높은 value에 해당하는 key값, 즉 color를 저장해둠
print(color_class)
color = max(color_class, key=color_class.get)
print(color)

# 패션스타일 경로 저장 후 이를 폴더에 있는 모든 json을 불러오기 위해 glob 라이브러리 이용
folder_path = 'fashion_label/' + style + '/*.json'
File_List = glob.glob(folder_path)

# 반복문을 통해 category_id와 색상이 일치하는 패션 스타일 파일 이름 찾기 
# 이후 fashion_data 리스트에 사진에 대한 경로를 저장해둠
fashion_data = []

for i in File_List: 
    f = open(i,'r') 
    js = json.loads(f.read())
    dict = js["데이터셋 정보"]["데이터셋 상세설명"]["라벨링"][category_id][0]
    if category_id == '상의' :
        # 원피스 또한 상의 데이터로 분류하여 상의에 데이터가 없을 때 원피스에서도 찾기
        dict2 = js["데이터셋 정보"]["데이터셋 상세설명"]["라벨링"]['원피스'][0]
        if '색상' in dict :
            if dict['색상'] == color : 
                path = i.replace('json', 'jpg')
                path = path.replace('label', 'image')
                fashion_data.append(path)
        elif '색상' in dict2 :
            if dict2['색상'] == color : 
                path = i.replace('json', 'jpg')
                path = path.replace('label', 'image')
                fashion_data.append(path)
    else :
        if '색상' in dict :
            if dict['색상'] == color : 
                path = i.replace('json', 'jpg')
                path = path.replace('label', 'image')
                fashion_data.append(path)
    f.close()

# fashion_data에 저장한 코디 데이터 사진 결과 중 5개 랜덤으로 추출 후 이를 확인
random_fashion = random.sample(fashion_data, 5)

for i in random_fashion :
    print(i)

image = Image.open(random_fashion[0])
image.show()