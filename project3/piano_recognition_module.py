import cv2
import numpy as np

#frame에 contours를 그리는 함수
def draw_keys(frame, contours):
    for i in range(len(contours)):
        cv2.drawContours(frame, [contours[i]], 0, (0,255, 0), 2)

#frame에 contours를 그려서 새로운 창으로 띄우는 함수
def print_keys(origianl, contours, name):
    frame = origianl.copy()
    for i in range(len(contours)):
        cv2.drawContours(frame, [contours[i]], 0, (0,0, 255), 2)  #컨투어 프레임에 그리기
        cv2.putText(frame, str(i), tuple(contours[i][0][0]), cv2.FONT_HERSHEY_COMPLEX, 0.8, (255, 0, 0), 1) #키보드 번호 텍스트 넣기
        cv2.imshow("print " + name, frame)            #이미지 show
    return frame

#contour를 scale하는 함수 https://github.com/nvs-abhilash/tutorials/blob/master/tutorials/opencv_contour_scale_rotate/Scaling%20and%20Rotating%20contours.ipynb
def scale_contour(cnt, scale): 
    M = cv2.moments(cnt)
    cx = int(M['m10']/M['m00'])
    cy = int(M['m01']/M['m00'])

    cnt_norm = cnt - [cx, cy]
    cnt_scaled = cnt_norm * scale
    cnt_scaled = cnt_scaled + [cx, cy]
    cnt_scaled = cnt_scaled.astype(np.int32)

    return cnt_scaled

#contour를 sort하는 함수 https://pyimagesearch.com/2015/04/20/sorting-contours-using-python-and-opencv/ 
def sort_contours(cnts, method="left-to-right"):
	# initialize the reverse flag and sort index
	reverse = False
	i = 0

	# handle if we need to sort in reverse
	if method == "right-to-left" or method == "bottom-to-top":
		reverse = True
    
	# handle if we are sorting against the y-coordinate rather than
	# the x-coordinate of the bounding box
	if method == "top-to-bottom" or method == "bottom-to-top":
		i = 1
	# construct the list of bounding boxes and sort them from top to
	# bottom
	boundingBoxes = [cv2.boundingRect(c) for c in cnts]
	(cnts, boundingBoxes) = zip(*sorted(zip(cnts, boundingBoxes),
		key=lambda b:b[1][i], reverse=reverse))
	# return the list of sorted contours and bounding boxes
	return (cnts, boundingBoxes)


#흰색 건반들을 찾는 함수
def finding_keys_white(frame):
    key_num=7
    '''''''필요한 파일들 세팅'''''''
    #original = cv2.imread('source/piano_frame_up.jpg')
    original = frame
    blank = np.zeros(original.shape[:2], dtype='uint8')
    blur = cv2.GaussianBlur(original, (3,3), 0)
    cv2.imshow('blur', blur)
    #blur = original
    gray = cv2.cvtColor(blur, cv2.COLOR_BGR2GRAY)
    canny = cv2.Canny(gray, 120, 175)
    _, thresh = cv2.threshold(gray, 130, 255, cv2.THRESH_BINARY) #binarying the image

    '''''''피아노(사각형) 찾아서 마스킹하기'''''''
    cnts, _ = cv2.findContours(canny.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = sorted(cnts, key = cv2.contourArea, reverse = True)[:5]
    #c = cnts[1]
    c = max(cnts, key=cv2.contourArea)
    cnt_scaled = scale_contour(c, 0.98)
    piano_mask = cv2.drawContours(blank, [cnt_scaled], 0, 255, -1)
    #original = cv2.drawContours(original, [cnt_scaled], 0, (0,0,255), 3)
    #cv2.imshow('Mask', piano_mask)
    #cv2.imshow('original', original)

    '''''''흰색 키 마스킹'''''''
    w_masked = cv2.bitwise_and(thresh, thresh, mask=piano_mask)
    #cv2.imshow('Wmasked', w_masked)

    w_cnts, _ = cv2.findContours(w_masked, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    w_cnts = sorted(w_cnts, key = cv2.contourArea, reverse = True)[:key_num]


    print(len(w_cnts))
    white_mask = np.zeros(original.shape[:2], dtype='uint8')

    for i in range(len(w_cnts)):
        white_mask = cv2.drawContours(white_mask, [w_cnts[i]], 0, 255, -1)
        #cv2.imshow("White", white_mask)

    '''''''흰색 키 왼쪽부터 sort하기'''''''
    white_key, _ = cv2.findContours(white_mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    print(len(white_key))
    sorted_white_keys, _ = sort_contours(white_key, method="right-to-left")#[:key_num]

    return sorted_white_keys


def finding_keys_black(frame):
    key_num=5
    '''''''필요한 파일들 세팅'''''''
    #original = cv2.imread('source/piano_frame_up.jpg')
    original = frame
    blank = np.zeros(original.shape[:2], dtype='uint8')
    blur = cv2.GaussianBlur(original, (3,3), 0)
    cv2.imshow('blur', blur)
    #blur = original
    gray = cv2.cvtColor(blur, cv2.COLOR_BGR2GRAY)
    canny = cv2.Canny(gray, 120, 175)
    gray = 255 - gray
    _, thresh = cv2.threshold(gray, 130, 255, cv2.THRESH_BINARY) #binarying the image

    '''''''피아노(사각형) 찾아서 마스킹하기'''''''
    cnts, _ = cv2.findContours(canny.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = sorted(cnts, key = cv2.contourArea, reverse = True)[:5]
    #c = cnts[1]
    c = max(cnts, key=cv2.contourArea)
    cnt_scaled = scale_contour(c, 0.94)
    piano_mask = cv2.drawContours(blank, [cnt_scaled], 0, 255, -1)
    #original = cv2.drawContours(original, [cnt_scaled], 0, (0,0,255), 3)
    #cv2.imshow('Mask', piano_mask)
    #cv2.imshow('original', original)

    '''''''흰색 키 마스킹'''''''
    b_masked = cv2.bitwise_and(thresh, thresh, mask=piano_mask)
    #cv2.imshow('Wmasked', w_masked)

    b_cnts, _ = cv2.findContours(b_masked, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    b_cnts = sorted(b_cnts, key = cv2.contourArea, reverse = True)[:key_num]


    print(len(b_cnts))
    black_mask = np.zeros(original.shape[:2], dtype='uint8')

    for i in range(len(b_cnts)):
        black_mask = cv2.drawContours(black_mask, [b_cnts[i]], 0, 255, -1)
        #cv2.imshow("White", white_mask)

    '''''''흰색 키 왼쪽부터 sort하기'''''''
    black_key, _ = cv2.findContours(black_mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    print(len(black_key))
    sorted_black_keys, _ = sort_contours(black_key, method="right-to-left")#[:key_num]

    return sorted_black_keys

def finding_keys(frame):
    keys = finding_keys_black(frame) + finding_keys_white(frame)
    sorted, _ = sort_contours(keys, method="right-to-left")
    return sorted