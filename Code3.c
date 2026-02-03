
                    printf("%d ", i);
                }
            }
            break;

        case 3:
            printf("Enter a number: ");
            scanf("%d", &num);

            for (i = 1; i <= num; i++) {
                fact = fact * i;
            }

            printf("Factorial of %d is %d", num, fact);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
