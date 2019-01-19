clear
clc

% Beispiel Klassifikation 2 Ausgangsneuronen

% Generiere x_1 und x_2 Daten zufallsbasiert
anz = 100; 
dat = [randn(anz,2); randn(anz,2) + 2]; % anz x 2 Matrix 

code = [ones(anz,1); 2*ones(anz,1)];
code_n = [2-code, code-1];              % bis Zeile 100 habe ich 1 0, danach bis 200 habe ich 0 1 als Eintraege

% Test Data - aequidistante Eingabedaten fuer x_1 und x_2
dat_test = []; 
for x=-2:0.5:4
    for y = -2:0.5:4
        dat_test = [dat_test; [x y]]; 
    end; 
end;

% Set up and train Network
net1 = newff(dat',code_n',20);
net1 = train(net1, dat',code_n');

% Wende Netz auf Eingangedaten an
outputs1 = net1(dat_test');

figure; 
set(gca,'xlim',[-2 4], 'ylim', [-2 4]);
for i=1:size(dat_test,1)
    text(dat_test(i,1), dat_test(i,2), sprintf('(%1.1f/%1.1f)', outputs1(1,i), outputs1(2,i))); 
end;

% Erstelle Plot mir den Maximalwerten des Outputs
[tmp, out] = max(outputs1,[],1);
figure; 
set(gca,'xlim',[-2 4], 'ylim', [-2 4]);
for i=1:size(dat_test,1) 
    text(dat_test(i,1), dat_test(i,2), sprintf('%i', out (i))); 
end;


