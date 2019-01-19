%test configure

x1 =  [4 5 6];
x2 =  [0 1 0];
x = {x1;x2};
t = [0 0 1];
net = feedforwardnet;
net.numinputs = 2;
net.inputConnect = [1 1; 0 0];
net = configure(net,x);
net = train(net,x,t);
view(net)