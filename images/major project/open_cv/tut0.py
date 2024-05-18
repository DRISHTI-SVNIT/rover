import cv2 as cv
import numpy as np

img = cv.read('photos/banswara.jpg')
cv.imshow('img',img)

def rescaleFrame(frame,scale):
    width = int(frame.shape[1]*scale)
    height = int(frame.shape[0]*scale)

    dimensions = (width,height)
    return cv.resize(frame ,dimensions, interpolation=cv.INTER_AREA)

capture = cv.VideoCapture('VIDEOADDRESS')

while True:
    isTrue , frame = capture.read()
    cv.imshow('Video',frame)
    frame_resize = rescaleFrame(frame,0.75)
    cv.imshow('Video_resize',frame_resize)
    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows

cv.waitKey(0)

