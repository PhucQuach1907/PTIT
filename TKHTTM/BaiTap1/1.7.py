import numpy as np

# Given data
names = np.array(['Ann', 'Joe', 'Mark'])
heights = np.array([1.5, 1.78, 1.6])
weights = np.array([65, 46, 59])

# Calculate BMI for each individual
bmi_values = weights / (heights ** 2)

# Define BMI categories
underweight_threshold = 18.5
overweight_threshold = 25

# Classify individuals based on BMI
bmi_categories = []
for bmi in bmi_values:
    if bmi < underweight_threshold:
        bmi_categories.append('Underweight')
    elif bmi > overweight_threshold:
        bmi_categories.append('Overweight')
    else:
        bmi_categories.append('Normal weight')

# Display results for each individual
for i in range(len(names)):
    print(f"{names[i]} - BMI: {bmi_values[i]:.2f} - Category: {bmi_categories[i]}")
