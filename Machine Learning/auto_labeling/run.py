# run.py
from auto_labeling import *

user_name = "一颗赛艇"
iter_num = 5000

L = Naive_Label_Client(user_name)
L.run(iter_num)