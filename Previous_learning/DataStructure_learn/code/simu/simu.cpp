void simulate(int nWin, int servTime){//指定窗口数、服务总时间模拟银行业务
    Queue<Customer>* windows = new Queue<Customer>[nWin];//为每一窗口创建一个队列
    for (int now = 0; now < servTime; now++){//在下班之前，每隔一个单位时间
        if (rand() % (1 + nWin)){//新顾客以nWin/(nWin+1)的概率到达
            Customer c; c.time = 1 + rand() % 98;//新顾客到达，服务时长随机确定
            c.window = bestWindow(windows, nWin);//找出最佳(最短)的服务窗口
            windows[c.window].enqueue(c);//新顾客加入队列
        }
        for (int i = 0; i < nWin; i++){//分别检查
            if(!windows[i].empty())//各非空队列
                if (--windows[i].front().time <= 0)//队首顾客的服务时长减少一个单位
                    windows->dequeue();//服务完毕的顾客出列,由后续顾客接替
        }
    }//for
    delete [] windows;//释放所有队列(此前，~List()会自动清空队列)
}
