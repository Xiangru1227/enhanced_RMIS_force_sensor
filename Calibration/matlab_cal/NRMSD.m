function result = NRMSD(a,b)

result = (RMSE(a,b) ./ (max(b) - min(b))) * 100;
% This is an percentage. Needs a % when printed.

end