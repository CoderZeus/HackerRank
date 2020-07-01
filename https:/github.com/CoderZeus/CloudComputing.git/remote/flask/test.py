import cv2
import numpy as np

# Load Yolo
model = "/home/ubuntu/sharath/yolo/yolov3-tiny.weights"
config = "/home/ubuntu/sharath/yolo/w.cfg"

net = cv2.dnn.readNet(model,config)
classes = []
with open("coco.names", "r") as f:
    classes = [line.strip() for line in f.readlines()]
layer_names = net.getLayerNames()
output_layers = [layer_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]
colors = np.random.uniform(0, 255, size=(len(classes), 3))

# Loading image
img = cv2.imread("room_ser.jpg")
img = cv2.resize(img, None, fx=0.4, fy=0.4)
height, width, channels = img.shape

# Detecting objects
blob = cv2.dnn.blobFromImage(img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)
net.setInput(blob)
outs = net.forward(output_layers)
#print(output_layers)
print('###############################')
#print(outs)
print('#######################')
#print(classes)
# Showing informations on the screen
class_ids = []
confidences = []
boxes = []
data ='{ "objects": [ \n'
for out in outs:
    for detection in out:
        scores = detection[5:]
        class_id = np.argmax(scores)
        confidence = scores[class_id]
        #print(class_id,confidence)
        if confidence > 0:
            print(classes[class_id],confidence*100)
            data = data +'\n \t { "label": "' +str(classes[class_id]) + '" ,"accuracy": "' + str(confidence*100) + '" }, '
                    
data = data[:-2] +'\n  ] \n }'


print(data)        

#def make_Json(data,classname,confidence):
    

"""			
indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.1, 0.4) 
print(indexes)
font = cv2.FONT_HERSHEY_PLAIN
for i in range(len(boxes)):
    if i in indexes:
        x, y, w, h = boxes[i]
        label = (classes[class_ids[i]])
        color = colors[i]
        cv2.rectangle(img, (x, y), (x + w, y + h), color, 2)
        cv2.putText(img, label, (x, y + 30), font, 3, color, 3)
        print(label)
cv2.imshow("Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
"""
