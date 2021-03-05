// book.c

inherit ITEM;

void create()
{
    int	i;

   string *names = ({
        "「棍术入门」", "「拳法入门」", "「剑术入门」","「鞭术入门」",
        "「拆招秘决」", "「闪躲之术」", "「锤法入门」","「刀术入门」",
        "「枪法入门」", "「斧法入门」"
    });

    string *skills = ({
        "staff", "unarmed", "sword", "whip","parry", "dodge","hammer","blade","spear","axe"
    });
 	i = random(10);
    set_name( names[i], ({ "book" }));
    set_weight(100);
    set("unit", "本");
    set("long", "这是一本修练基本武功的书籍。\n");
    set("skill", ([
        "name":                 skills[i],
        "exp_required": 0,                
        "sen_cost":             20,     
        "difficulty":   20,            
        "max_skill":    15           
                                            
        ]) );
	::init_item();
}
