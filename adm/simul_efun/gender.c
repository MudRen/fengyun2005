// gender.c
#include <gender.h>
#include <pronoun.h>
string gender_self(string sex)
{
        switch(sex) {
                case "女性": return "你";       break;
                default: return "你";
        }
}

string gender_pronoun(string sex)
{
        switch(sex) {
                case "中性神":  return "他";    break;
                case "男性":    return "他";    break;
                case "女性":    return "她";    break;
                case "雄性":
                case "雌性":    return "它";    break;
                default: return "它";
        }
}

string pnoun(int pronoun_number, mixed arg)
{
        if( objectp(arg) ) 
                arg = arg->query("gender");
        
        switch(pronoun_number)
        {
                case FIRST_PERSONAL:    
                        return FIRST_PERSONAL_PRONOUN;
                
                case SECOND_PERSONAL: 
                        switch( arg )
                        {
                                case MALE_GENDER:       return SECOND_PERSONAL_PRONOUN_MALE;    break;
                                case FEMALE_GENDER:     return SECOND_PERSONAL_PRONOUN_FEMALE;  break;
                                default:                return SECOND_PERSONAL_PRONOUN_DEFAULT; break;
                        }

                case THIRD_PERSONAL:    
                        if( undefinedp(arg) )
                                return THIRD_PERSONAL_PRONOUN_ANIMAL;     
                        switch( arg )
                        {
                                case MALE_GENDER:       return THIRD_PERSONAL_PRONOUN_MALE;     break;
                                case FEMALE_GENDER:     return THIRD_PERSONAL_PRONOUN_FEMALE;   break;
                                case ANIMAL_GENDER:     return THIRD_PERSONAL_PRONOUN_ANIMAL;   break;
                                default:                return THIRD_PERSONAL_PRONOUN_DEFAULT;  break;
                        }
                default:
                        error("错误人称代名词。\n");
        }
}
