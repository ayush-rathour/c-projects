// Airline Ticket Fare & Eligibility Checker
#include <stdio.h>
int main()
{
    int age, travelDay, isMember, baggage;
    int baseFare = 3000;
    int ageDiscount, daySurcharge, membershipDiscount, totalFare;

    printf("===== WELCOME ======");
    printf("\nEnter Passenger Age: ");
    scanf("%d", &age);
    printf("Enter Travel Day (1-7): ");
    scanf("%d", &travelDay);
    printf("Enter Membership Status (1/0): ");
    scanf("%d", &isMember);

    totalFare = baseFare;

    // Travel Day Surcharge
    if (travelDay >= 1 && travelDay <= 5)
    {
        daySurcharge = 0;
    }
    else if (travelDay == 6 || travelDay == 7)
    {
        daySurcharge = 300;
    }
    else
    {
        printf("Invalid Input");
        return 0;
    }

    totalFare += daySurcharge;

    // Age Logic
    if (age < 2)
    {
        ageDiscount = (totalFare) * 90 / 100;
        baggage = 5;
        printf("\nFare : 90%% off");
    }
    else if (age >= 2 && age < 12)
    {
        ageDiscount = (totalFare) * 25 / 100;
        baggage = 15;
        printf("\nFare : 25%% off");
    }
    else if (age >= 12 && age < 60)
    {
        ageDiscount = 0;
        baggage = 20;
        printf("\nFare : Unchanged");
    }
    else if (age >= 60)
    {
        ageDiscount = (totalFare) * 20 / 100;
        baggage = 20;
        printf("\nFare : 20%% off");
    }
    else
    {
        printf("Invalid Input");
        return 0;
    }

    totalFare -= ageDiscount;

    // Membership Eligibility
    if (isMember == 1)
    {
        if (age >= 2)
        {
            membershipDiscount = (totalFare) * 10 / 100;
            printf("\nMembership Status : Active\n10%% Off Claimed");
        }
        else
        {
            membershipDiscount = 0;
            printf("\nMembership Status : Active (Infant)\nAlready Discounted, No extra Discount.");
        }
    }
    else
    {
        membershipDiscount = 0;
        printf("\nMembership Status : InActive\nNo Discount Available");
    }

    totalFare -= membershipDiscount;

    printf("\n\n===== Ticket ====="
           "\nAge : %d"
           "\nTravel Day : %d"
           "\nMembership : %d"
           "\nBaggage : %dKg"
           "\nBaseFare : %d"
           "\nDiscount : %d"
           "\nPayable Amt. : %d"
           "\n===== Thanks =====",
           age, travelDay, isMember, baggage, baseFare, ageDiscount + membershipDiscount, totalFare);
}