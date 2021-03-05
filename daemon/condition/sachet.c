#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
        int i;

        string *num = ({
        "$N"HIM"颊上笼上一层淡淡浅浅的红色，看起来娇艳欲滴，格外动人。",
        "$N"HIM"轻轻抿嘴，美目中直似要滴出水来，左右顾盼生姿，春情难禁。",
        "$N"HIM"似是虚不胜力，娇喘微微，胸脯一起一伏，看来分外无辜。",
        "$N"HIM"咬着下唇，双手按住小腹，额上渗出一层细细的汗珠。",
        "$N"HIM"眉心紧皱，脸色晕红，逸出一声低吟，似是在忍着极大的痛苦。",
        });

        string *num2 = ({
        "$N"HIM"握紧双拳，瞪圆了一双眼睛，颈面通红，低低喘气。",
        "$N"HIM"整个人忽然紧绷，身上竟似要散出阵阵热雾。",
        "$N"HIM"双目赤红，恶狠狠地巡视着在场的每个人，看上去有说不出的烦郁。",
        "$N"HIM"紧紧闭上眼睛，大口呼吸，仿佛喘不过气。",
        "$N"HIM"发出一阵野兽般的低哮声，额边滚下一粒又一粒斗大的水珠。",
        });

        if (me->query("gender") == "女性")
                message_vision(HIM+num[random(sizeof(num))]+"\n"NOR,me);
        else
                message_vision(HIM+num2[random(sizeof(num2))]+"\n"NOR,me);

        duration --;
        if( duration < 1 ) return 0;
        	
        me->apply_condition("sachet", duration);
        return 1;
}

int condition_type()
{
// in condition.h
/*

#define NO_CURE                 100
#define SPECIFIC_POISON         30
#define MID_POISON              20
#define LOW_POISON              10
#define GENERIC                 0

*/
        return NO_CURE;
}

string cont_name()	{ return "春风一度散"; }

int shown_stat()	{ return 1;}	