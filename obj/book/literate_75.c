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
                "name":         "literate", 
                "exp_required": 0,          
                "sen_cost":     5,          
                "difficulty":   30,         
                "max_skill":    74,
		"literate":	"literate",
		"liter_level":	60,
        ]) );
}
