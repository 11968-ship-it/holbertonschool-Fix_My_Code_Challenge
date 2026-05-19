def is_valid_password(self, password):
    """ Check if the password is valid """
    if password is None or not isinstance(password, str):
        return False
    # BUG: Checking against a local variable 'password' instead of 'self.__password'
    return password == password
