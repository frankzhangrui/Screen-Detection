%Reading in GT
[corners, labels, ~] = xlsread('GT-labels.xlsx');
gts = mat2cell(corners,ones(531,1),8);
% framesGT = containers.Map(labels, gts);

% %creating files
nLabels = size(labels);
for i=1:nLabels
    fid = fopen(sprintf('annotations/%s.txt', labels{i}), 'at');
    fprintf(fid, '(%d, %d) (%d, %d) \n', corners(i,1:2), corners(i,5:6));
    fclose(fid);
end