# Console Based Shopping App

## Author
Muhammad Ahmad

## Overview

Our console-based shopping app program consists of 9 classes:

1. **User, Costumer, Seller**
   - Derived classes from the User class.

2. **Product, Furniture, Electronic, Clothing**
   - Derived classes from the Product class.

3. **ProductManagment**
   - Composite of Furniture, Electronic, and Clothing classes.
   - Dynamically allocated arrays for managing products added by sellers.
   - Functions to add and delete products, as well as display available products.

4. **Cart**
   - Composite of Furniture, Electronic, and Clothing classes (copied from ProductManagment).
   - Dynamically allocated arrays for managing products added to the virtual cart by customers.
   - Functions to add and delete items from the cart, display cart contents, and calculate the total sum.

## Class Structure and Functions

### User, Costumer, Seller Classes
- Attributes and functions to display and set values.
- User class includes a login() function for user authentication.

### Product, Furniture, Electronic, Clothing Classes
- Attributes and functions for displaying and setting values.

### ProductManagment Class
- Composite of Furniture, Electronic, Clothing classes.
- Dynamically allocated arrays for each product type.
- Functions to add and delete products, display available products.

### Cart Class
- Composite of Furniture, Electronic, Clothing classes.
- Dynamically allocated arrays for products added to the virtual cart.
- Functions to add and delete items from the cart, display cart contents, calculate total sum.
- Associated with ProductManagment class.

## Program Execution Flow

1. Object creation for Seller and Costumer in the main body.
2. User prompted to create seller and buyer accounts.
3. Friendly user menu for login as a seller or customer.
4. After login validation, the respective user interference functions are called:
   - `sellerUserInterferance()` for sellers
   - `buyerUserInterferance()` for customers

## Note
- Program uses bool type variables for user-friendly messages (e.g., "Cart is empty").
