function result = R2(a,b)

result = 1 - (sum((a - b).^2)) / (sum((a - mean(a)).^2));

end