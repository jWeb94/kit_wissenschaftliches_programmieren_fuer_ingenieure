% Beispiel Selbststudium Regression

anz = 100; 
x = [0.1:0.1:10];
x_2 = [0.1:0.1:10];
y = 2*x + randn(1, length(x));
figure;
plot(x, y, '*');
%net = newff(x, y, 3); % 3 -> 3 Neuronen im hidden Layer, x-Range definiert durch x, y defniert Ausgaberange
net = feedforwardnet([10]); % Hier wird das Ergebnis nicht richtig
%abgebildet, da das Netz zu viele Parameter hat. Wir bekommen Overfitting
%net = feedforwardnet([3]); % 3 Neuronen sind für das Problem geeignet!
net = configure(net, x, y);
net = train(net, x, y);
y_sim = net(x);
figure;
plot(x, y_sim, '*')
