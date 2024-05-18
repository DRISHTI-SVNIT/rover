import cv2
import os
vidcap = cv2.VideoCapture('videos/1/busAurGhass.mp4')
path = "Images/1"
def getFrame(sec):
    vidcap.set(cv2.CAP_PROP_POS_MSEC,sec*1000)
    hasFrames,image = vidcap.read()
    if hasFrames:
        cv2.imwrite(os.path.join(path ,"image"+str(count)+".jpg"), image)    # save frame as JPG file
    return hasFrames
sec = 0
frameRate = 0.25 #//it will capture image in each 0.5 second
count=1
success = getFrame(sec)
while success:
    count = count + 1
    sec = sec + frameRate
    sec = round(sec, 2)
    success = getFrame(sec)