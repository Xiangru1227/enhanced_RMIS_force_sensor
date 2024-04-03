function result = RMSE(a,b)

result = sqrt(mean((a - b).^2));

end