import numpy as np
from sklearn.linear_model import LinearRegression

# Sample data: (height in cm, weight in kg)
data = np.array([
    [150, 45],
    [160, 50],
    [165, 55],
    [170, 60],
    [175, 65],
    [180, 70]
])
heights = data[:, 0].reshape(-1, 1)
weights = data[:, 1]

model = LinearRegression()
model.fit(heights, weights)

new_heights = np.array([[155], [168], [172]])
predicted_weights = model.predict(new_heights)

for height, weight in zip(new_heights, predicted_weights):
    print(f"Height: {height[0]} cm, Predicted Weight: {weight:.2f} kg")


