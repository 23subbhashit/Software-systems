struct Student{
    int id; // 0, 1, 2 ....
    char student_name[25];
    int student_age; 
    char student_address[160];
    char student_email[80];
    //Login Credentials
    char student_login_id[20];
    char student_password[20];
};
struct Faculty{
    int id;
    char faculty_name[25];
    char faculty_department[3];
    char faculty_designation[50]; 
    int faculty_age; 
    char faculty_address[160];
    char faculty_email[80];
    //Login Credentials
    char faculty_address_login_id[20];
    char faculty_password[20];
};
