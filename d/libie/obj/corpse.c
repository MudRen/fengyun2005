// corpse.c

inherit ITEM;

int decayed;

void create()
{
        set_name("浑身是血的尸体", ({ "bloody corpse","corpse" }) );
        set("long", "这是一具沾满血污的尸体，死状恐怖狰狞。从服饰上看来似乎是衙门的捕头。\n");
        set("unit", "具" );
        set("age", 20+ random(20));
	set("gender", "男性");
	set("race", "汉族");
	set("victim_name", "捕头");
        decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + 
"开始腐烂了，发出一股难闻的恶臭。\n" );
                        switch(query("gender")) {
                                case "男性":
                                        set_name("腐烂的男尸", ({ "corpse", 
"尸体" }) );
                                case "女性":
                                        set_name("腐烂的女尸", ({ "corpse", 
"尸体" }) );
                                default:
                                        set_name("腐烂的尸体", ({ "corpse", 
"尸体" }) );
                        }
                        set("long",     
"这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        message("vision", query("name") + "被风吹乾了，变成一具骸骨。\n" ,environment());
                        set_name("一具枯乾的骸骨", ({ "skeleton", "骸骨" }) 
);
                        set("long", "这副骸骨已经躺在这里很久了。\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        message("vision", "一阵风吹过，把" + query("name") + 
"化成骨灰吹散了。\n" ,environment());
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
{
	if((int) inv[i]->query("no_get") ||
	((int) !inv[i]->value() &&
	(int) !inv[i]->query("value")))
	destruct(inv[i]);
	else
	inv[i]->move(environment());
}
                        }
                        destruct(this_object());
                        break;
        }
}

object animate(object who, int level)
{
        object zombie;
        string name;
        int zskill;

        if( !environment() ) return 0;
        seteuid(getuid());
        zombie = new("/obj/npc/zombie");
        zombie->set_name( (string)query("victim_name") + "的僵尸", ({ 
"zombie" }) );
        zombie->move(environment());
        zombie->animate(who, level);

        destruct(this_object());
        return zombie;
}
 
