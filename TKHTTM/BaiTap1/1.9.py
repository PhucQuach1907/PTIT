import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('driver_data.csv')

# Create a categorical plot using Seaborn
plt.figure(figsize=(8, 6))
sns.set(style="whitegrid")
sns.catplot(data=data, x="group", hue="gender", col="has_license", kind="count", height=6, aspect=0.8)
plt.suptitle("Proportion of Men and Women with Driver's License in Each Group", y=1.02)
plt.tight_layout()

# Display the plot
plt.show()

