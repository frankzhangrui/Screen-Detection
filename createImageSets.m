% [corners, labels, ~] = xlsread('GT-labels.xlsx');
% nLabels = size(labels,1);
% nTest = floor(nLabels/10);
% P = randperm(nLabels);
% test = labels(P(1:nTest));
% test{end}
% train = labels(P(nTest+1:end));
% train{end}
% fid = fopen('imagesets/test.txt', 'wt');
% for i=1:nTest
%     fprintf(fid, '%s\n', test{i});
% end
% fclose(fid);
for i=1:9%nLabels-nTest
%     fprintf('Processing train %d\n',i)
%     fid = fopen(sprintf('ImageSets/num/train%d.txt', i));
%     img_names = textscan(fid, '%s');
%     img_names = img_names{1};
%     fclose(fid);
%     selective_search_rcnn('Images',img_names, sprintf('train%d',i));
    
    fprintf('Processing test %d\n',i)
    fid = fopen(sprintf('ImageSets/num/test%d.txt', i));
    img_names = textscan(fid, '%s');
    img_names = img_names{1};
    fclose(fid);
    selective_search_rcnn('Images',img_names, sprintf('test%d',i));
end
% fclose(fid);