clear;
clc;

% Generiere ein Netz mit dem feedforwardnet Befehl

% Orginalfunktion
x = 0:.05:4;
x_2 = 3:0.05:7;
y = humps(x);
y_2 = sinc(x_2);

x_in = [x; x_2];
y_out = [y; y_2]; 

% Setze Netz auf
net = feedforwardnet([5, 3], 'trainlm'); % MLP mit 3 Layern, wobei der erste Layer 5 Neuronen, der zweite Layer 3 Neuronen und der 3. (Ausgabe-)Layer 1 Neuron hat. 
% Die Aktivierungsfunktiionen sind per Default tansig in den Hidden Layer
% und purelin im Ausgabelayer. Der Trainingsalgorithmus wurde hier auf
% trainbfg (Quasi Newton) gesetzt. Per Default ist es (ohne explizite
% Angabe) trainlm (Levenberg-Marquardt)

net.layers{1}.transferFcn = 'tansig'; % Schreibe ersten Layer mit Sigmoid-Aktivierungsfunktion!
% checke, ob das Umstellen geklappt hat: 
net.layers{1}.transferFcn

% Bestimme Ein-/Ausgabedimensionen des Netzes, basierend auf den
% Trainingsdaten (Anzahl der Kanaele fuer Input)
configuratedNet = configure(net, x_in, y_out); 


% Benenne Layer um und andere Einstellungen: 
configuratedNet.layers{1}.name = 'first layer';
configuratedNet.layers{2}.name = 'secound layer';
configuratedNet.layers{3}.name = 'output layer';

% Es gibt jede Menge weitere Einstellungen für das Netz! Siehe
% Doku/Autocomplete

view(configuratedNet);

trainedNet = train(configuratedNet, x_in, y_out);

% Praediktion des Netzes: 
pred = trainedNet(x_in);

%plot(x, pred(1,:));
%hold on;
plot(x_2, pred(2,:));

% Um bessere Ergebnisse zu erhalten müsste man Parametertuning machen!