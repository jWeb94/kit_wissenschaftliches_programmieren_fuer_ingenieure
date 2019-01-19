% Beispiel Klassifikation

anz = 100; 
dat = [randn(anz, 2); randn(anz,2)+2]; % Punktewolke mit x_1 und x_2 Komponente

code = [ones(anz, 1); 2*ones(anz, 1)];

% Visualisiere Train Daten - So Sieht der Input waehrend des Trainings für
% das Netz aus!
figure;
plot(dat(:,1), dat(:,2), '*');

for i = 1:size(dat, 1)
    text(dat(i, 1), dat(i,2), sprintf('%i', code(i))); % Ordnet Text den Datenpunkten zu - Ist ein Plot Befehl - dient nur der Visualisierung
    % Den ersten 100 Datenpunkten wird eine 1 zugeordnet, den zweiten 100
    % Punkten eine 2. 
end;

% Generiere Test Daten
dat_test = []; % Test Daten, die von x_1: -2 - 4 und x_2: -2 - 4 laufen (Zur Bestimmung der Prädiktion)
for x=-2:0.5:4
    for y = -2:0.5:4
        dat_test = [dat_test; [x y]]; % Gleichverteilte x_1 und x_2 Daten
    end; 
end;

% Visualisiere Test Daten
figure; 
plot(dat_test(:,1), dat_test(:,2), '*');

% Set up & train Network
net = newff(dat',code',20);     % 2 Input-, 1 Output-Kanal ~ 2 Layer mit 20 und 1 Neuronen
net = train(net, dat',code');

% Wende Netz an 
outputs = net(dat_test');   % Hier stecken die y-Komponenten zu den aequidistanten Test Daten drin. 

% Plotte Ergebnisse
figure; 
set(gca,'xlim',[-2 4], 'ylim', [-2 4]);
for i=1:size(dat_test,1)
    text(dat_test(i,1), dat_test(i,2), sprintf('%1.1f', outputs(i))); % Schreibe zugehoerigen, praedizierten Wert des Netzes Dazu
end;
