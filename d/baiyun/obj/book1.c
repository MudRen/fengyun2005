// sinny@fengyun
inherit ITEM;
void create()
{
        string *names = ({
                "【中庸】", "【荀子之修身篇】", "【荀子之劝学篇】",
                "【荀子之解蔽篇】", "【孝经】"
        });

        set_name( names[random(sizeof(names))], ({ "ethic book","book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是知书达礼的文人学者常看的先秦典籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "daode",             // name of the skill
                "exp_required": 5000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             15,                             // gin cost every time study this
                "difficulty":   30,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    35                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
