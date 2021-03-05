// annie 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
        set_name("萨昙分陀利经", ({ "chanting book","book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这本旧书的纸张都已经泛黄了，像是经常被人翻阅，上面似乎写着\n"
                        "一些经文。\n");
                set("value", 0);
                set("no_drop",1);
                set("material", "paper");
                set("skill", ([
                        "name":         "chanting",        
                        "exp_required": 100000,                         
                        "sen_cost":     2,                             
                        "difficulty":   20,             
                        "max_skill":    50              
                ]) );
        }
        ::init_item();
}

