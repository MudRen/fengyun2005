inherit ITEM;

void create()
{
	string *names=({"持国","广目","增长","多闻"});
	string name;
	name = names[random(sizeof(names))];
        set_name(name+"天王", ({ name+"天王", "tianwang" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "一座天王像\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

