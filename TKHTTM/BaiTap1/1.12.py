import numpy as np
from sklearn.linear_model import LinearRegression

# Original data
data = np.array([(50, 2.5), (60, 3), (65, 3.5), (70, 3.8), (75, 4), (80, 4.5), (85, 5)])

# Separate the data into two arrays: area and price
areas = data[:, 0].reshape(-1, 1)
prices = data[:, 1]

# Create a linear regression model
model = LinearRegression()

# Fit the model with the training data
model.fit(areas, prices)

# Predict prices for the given areas
new_areas = np.array([55, 68, 76, 90]).reshape(-1, 1)
predicted_prices = model.predict(new_areas)

# Print the prediction results
for area, price in zip(new_areas, predicted_prices):
    print(f"Area: {area} m2, Predicted Price: {price:.2f} billion")

