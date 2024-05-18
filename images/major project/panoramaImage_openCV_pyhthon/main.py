import cv2
import os


mainfolder = 'Images'
myFolders = os.listdir(mainfolder)
print(myFolders)

for folder in myFolders:
    path = mainfolder +'/'+folder
    print(path)
    images=[]
    myList = os.listdir(path)
    print(f"total no of image detected {len(myList)}")
    for imgN in myList:
        dim=(1024,768)
        imagepath = path+'/'+imgN
        print(imagepath)
        image = cv2.imread(imagepath,cv2.IMREAD_COLOR)
        image = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
        images.append(image)


    stitcher = cv2.Stitcher.create()
    ret,pano = stitcher.stitch(images)

    if ret==cv2.STITCHER_OK:
        print("panorama generated")
        cv2.imshow(folder,pano)
        cv2.waitKey(10)
    else:
        print("Error during Stitching")

cv2.waitKey(0)