% Zielfunktion
x = 0:.05:4;
y = humps(x);
y_2 = sinc(x);

%P = x; 
P = [x;x]; 
%T = [y; y_2]; 
T = y; 

%plot(P,T(1), 'x')
plot(P(1),T,'x');
grid; xlabel('time (s)'); ylabel('output'); title('humps function');

% DESIGN THE NETWORK
% ==================
%First try a simple one – feedforward (multilayer perceptron) network
%net=newff([0 3], [5,5,2], {'tansig','tansig','purelin'},'trainbfg'); % 2
%Outputs
net = newff([0 2; 0 2],[5, 1],{'tansig', 'purelin'}, 'trainbfg'); % 2 Inputs
% Here newff defines feedforward network architecture.
8% The first argument [0 2] defines the range of the input and initializes the network parameters.
% The second argument the structure of the network. There are two layers.
% 5 is the number of the nodes in the first hidden layer,
% 1 is the number of nodes in the output layer,
% Next the activation functions in the layers are defined.
% In the first hidden layer there are 5 tansig functions.
% In the output layer there is 1 linear function.
% ‘learngd’ defines the basic learning scheme – gradient method

% Define learning parameters
net.trainParam.show = 50; % The result is shown at every 50 th iteration (epoch)
net.trainParam.lr = 0.05; % Learning rate used in some gradient schemes
net.trainParam.epochs =1000; % Max number of iterations
net.trainParam.goal = 1e-3; % Error tolerance; stopping criterion

%Train network - hier wird immer der gesamte, verfügbare Datensatz
%trainiert. Wir sind ja daran interessiert, eine möglichst gute
%repräsentation zu finden!
net1 = train(net, P, T); % Iterates gradient type of loop
% Das trainierte Netz wird in net1 gesichert. In net ist quasi das 'rohe',
% untrainierte Netz, das als Eingabe in den Trainingsloop verwendet wird!

% Simulate how good a result is achieved: Input is the same input vector P.
% Output is the output of the neural network, which should be compared with output data
a= sim(net1,P); % gebe die Daten P ins Netz hinein, um die resultierende Prädiktion zu sehen!

% Plot result and compare
plot(P,a-T, P,T); grid;

