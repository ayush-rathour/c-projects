#include <stdio.h>
int main()
{
    int age, day, genre, genre_charges, is_member, membership;
    int slot_discount, age_discount, membership_discount, final_price;
    int base_price = 200;

    printf("=== WELCOME TO OUR CINEMA ===\n4 Movie Genres Available\nBase Charges = 200\n");

    printf("\n=== Movie Genre ===\n"
           "1. Action 50+\n"
           "2. Comedy 20+\n"
           "3. Horror 30+\n"
           "4. Animation 10+\n"
           "Enter: ");
    scanf("%d", &genre);

    printf("Enter day slot here (1-7): ");
    scanf("%d", &day);

    printf("Enter the age here: ");
    scanf("%d", &age);

    printf("Membership Status (1/0): ");
    scanf("%d", &membership);

    // Genre Charges
    switch (genre)
    {
    case 1:
        genre_charges = 50;
        break;
    case 2:
        genre_charges = 20;
        break;
    case 3:
        genre_charges = 30;
        break;
    case 4:
        genre_charges = 10;
        break;

    default:
        printf("Invalid Genre Choice\n");
        return 0;
    }

    // Slot Discount
    if (day >= 1 && day <= 5)
    {
        slot_discount = (base_price + genre_charges) * 10 / 100;
    }
    else if (day == 6 || day == 7)
    {
        slot_discount = 0;
    }
    else
    {
        printf("Invalid Day Choosen\n");
        return 0;
    }

    // Age Discount
    if (age <= 12)
    {
        age_discount = (base_price + genre_charges - slot_discount) * 50 / 100;
    }
    else if (age >= 13 && age <= 59)
    {
        age_discount = 0;
    }
    else if (age >= 60)
    {
        age_discount = (base_price + genre_charges) * 30 / 100;
    }
    else
    {
        printf("Invalid Age\n");
        return 0;
    }

    // Membership Discount
    if (membership == 1)
    {
        is_member = 1;
        if (age < 60)
        {
            membership_discount = (base_price + genre_charges - slot_discount - age_discount) * 15 / 100;
        }
        else
        {
            membership_discount = 0;
            printf("Priority Seating, No extra Discount\n");
        }
    }
    else
    {
        is_member = 0;
        membership_discount = 0;
    }

    // Final Price
    final_price = base_price + genre_charges - slot_discount - age_discount - membership_discount;

    // Final Combo Offer
    if (final_price < 100 && is_member)
    {
        printf("Free Popcorn Combo\n");
    }
    else if (final_price < 150 || age <= 12)
    {
        printf("Discounted Popcorn Combo\n");
    }
    else
    {
        printf("No Combo Available\n");
    }

    printf("\n=== Movie Ticket ===\n"
           "Genre Choice : %d | Extra Charges : %d\n"
           "Age : %d | Age Discount : %d\n"
           "Slot Discount : %d\n"
           "Membership : %d\n"
           "Payable Amt : %d\n",
           genre, genre_charges, age, age_discount, slot_discount, is_member, final_price);

    return 0;
}