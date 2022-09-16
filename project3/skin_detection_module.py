import cv2
import numpy as np
import imutils



def get_skinmask(frame):  #RGB값을 이용한 피부색의 mask 검출
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)     #프레임 이미지를 HSV 색공간으로 변경
    lowred = np.array([0, 30, 80])                   #skin color의 RGB영역 설정
    highred = np.array([15, 255, 255])

    red_mask = cv2.inRange(hsv, lowred, highred)  # skin color의 범위

    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))      #커널 구조화
    red_mask = cv2.morphologyEx(red_mask, cv2.MORPH_CLOSE, kernel, 1)  #
    return red_mask

def detect_skincontour(mask): #피부영역의 contour 추출
    contours, hierachy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) #피부 영역의 contour 검출
    contours = sorted(contours, key=lambda x: cv2.contourArea(x), reverse=True)
    return contours

def draw_crossline(frame,width,height):     #프레임에 가로선 그리기
    cv2.line(frame, (0, height), (width, height), (0, 255, 0), cv2.LINE_4)

def draw_verline(frame, x, height):           #프레임에 세로선 그리기
    cv2.line(frame, (x, 0), (x,height),(0,0,0), cv2.LINE_4, 2)