import cv2 as cv
import numpy as np

img = cv.imread('photos/banswara.jpg')

cv.imshow('Boston',img)

# translation
def translate(img,x,y):
    transMat = np.float32([[1,0,x],[0,1,y]])
    dimensions = (img.shape[1],img.shape[0])
    return cv.warpAffine(img,transMat,dimensions)

#-x --> left
#-y --> up
# x --> Right
# y --> Down

translated  = translate(img,-100,100)
cv.imshow('translated',translated)

#rotation
def rotate(img,angle,rotPoint=None):
    (height,width)=img.shape[:2]

    if rotPoint is None:
        rotPoint = (width//2,height//2 )

    rotMat = cv.getRotationMatrix2D(rotPoint,angle,1.0)
    dimension = (width,height)

    return cv.warpAffine(img,rotMat,dimension)


rotated = rotate(img,45)
cv.imshow('rotated',rotated)

#flipping 0 for vertical flipping 1 for horizontal flipping -1 for both
flip = cv.flip(img,1)
cv.waitKey(0)
