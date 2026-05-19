#!/usr/bin/python3
"""
User class
"""

class User():
    """ User class representation """

    def __init__(self):
        """ Init method """
        self.__email = None
        self.__password = None

    @property
    def email(self):
        """ Email getter """
        return self.__email

    @email.setter
    def email(self, value):
        """ Email setter """
        if type(value) is not str:
            raise TypeError("email must be a string")
        self.__email = value

    @property
    def password(self):
        """ Password getter """
        return self.__password

    @password.setter
    def password(self, value):
        """ Password setter """
        if type(value) is not str:
            raise TypeError("password must be a string")
        self.__password = value

    def is_valid_password(self, password):
        """ Check if the password is valid """
        if password is None or not isinstance(password, str):
            return False
        # FIX: Correctly comparing the parameter with the object's stored private password
        return password == self.__password


if __name__ == "__main__":
    print("Test User")
    u = User()
    u.password = "Root"
    if not u.is_valid_password("Root"):
        print("is_valid_password should return True if it's the right password")
