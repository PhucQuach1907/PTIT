import pandas as pd
import matplotlib.pyplot as plt

# Read the salary data from the CSV file
data = pd.read_csv('salary.csv')

# Separate data for men and women
men_data = data[data['gender'] == 'men']
women_data = data[data['gender'] == 'women']

# Create a scatter plot to show the distribution of salaries by gender
plt.figure(figsize=(8, 4))
plt.scatter(men_data['gender'], men_data['salary'], label='Men', color='blue')
plt.scatter(women_data['gender'], women_data['salary'], label='Women', color='pink')

# Add labels and title
plt.xlabel('Gender')
plt.ylabel('Salary')
plt.title('Distribution of Salaries by Gender')
plt.legend()

# Show the plot
plt.tight_layout()
plt.show()

