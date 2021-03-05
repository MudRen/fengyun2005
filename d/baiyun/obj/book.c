// sinny@fengyun
#include <ansi.h>
inherit ITEM;
void create()
{
        string *names = ({
             HIC"【兰亭序】"NOR, MAG"【洛神赋】"NOR, HIB"【丧乱帖】"NOR,
                             HIW"【快雪时晴帖】"NOR, HIY"【黄庭经】"NOR
        });

        set_name( names[random(sizeof(names))], ({ "calligraphy book","book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是文人学士梦寐以求的大家名帖的副本。\n");
        set("value", 150);
        set("skill", ([
                "name":                 "calligraphy",             // name of the skill
                "exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             25,                             // gin cost every time study this
                "difficulty":   30,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    60                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
