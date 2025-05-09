Financial Planner Goals:

  Create a script that tracks income and expenses, allows the user to categorize each transaction, and then generates useful insights (e.g., monthly summaries, visual reports, etc).

Features:

Input/Output:

  Add Transactions: Allow the user to input transactions (income or expense) via the command line. Each transaction should have:

    Amount

    Date

    Category (e.g., Food, Entertainment, Rent, etc.)

    Type (Income or Expense)

Data Storage:

  Store the transactions in a JSON file (transactions.json) to persist data across sessions.

  Each transaction should have a unique ID for easy tracking.

Monthly Summary Report:

  Generate a summary report for the current month:

    Total Income

    Total Expenses

    Savings (Income - Expenses)

    Breakdown of expenses by category (e.g., Food: $200, Rent: $800)

Visual Reports:

  Use matplotlib or seaborn to visualize the monthly expense breakdown by category.

  A pie chart or bar graph to represent the distribution of expenses.

Categories and Budget Alerts:

  Allow users to set a budget for each category (e.g., food budget: $500).

  Notify the user when they’re close to exceeding or have exceeded their budget for a category.

Data Validation:

  Implement error handling and validation:

  Ensure only valid amounts (numbers) are entered.

  Ensure the date is valid.

  Ensure correct categories are selected.

Command-line Interface:

  Use Python’s argparse to create a clean CLI for interacting with the tracker.

  Offer the following options in the CLI:

    Add transaction

    View monthly summary

    Set budget

    Show transaction history

Export/Import to CSV:

  Implement functionality to export the transaction data to a CSV file for further analysis.

  Allow importing transactions from a CSV to quickly populate the tracker.

Recurring Transactions:

  Support for recurring transactions (e.g., rent, subscription services).

  Have the program automatically add these transactions on a set schedule.

Data Encryption:

  Implement basic encryption (using cryptography library) to secure the JSON data file.

Implementation:
  main.py - Main script that runs the CLI and handles the flow of the application.
  utils.py - Helper functions for tasks like reading/writing JSON, handling transactions, etc.
  visualizations.py - Handles data visualization (bar chart, pie chart, etc.).
  categories.py - For managing categories and budgets.
