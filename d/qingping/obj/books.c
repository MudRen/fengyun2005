// XXDER
inherit ITEM;
void create()
{
        string *names = ({
                "「老子」", "「春秋」", "「墨子」",
                "「论语」", "「孙子」"
        });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600);
        set("unit", "本");
        set("long", "这是读书人常看的书籍。\n");
        set("value", 100);
        set("skill", ([
                "name":                 "literate",             // name of the skill
                "exp_required": 0,                              // minimum combat experience required
                                                                                // to learn this skill.
                "sen_cost":             15,                             // gin cost every time study this
                "difficulty":   30,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    75                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}
