#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int direct();
void consider();

void create()
{
    set_name("裸体男人", ({"nakedman chu" }));
    set("title", HIY "妙绝天下"NOR );
    set("gender", "男性");
    set("age", 32);
    set("long",
        "
他双眉被面长，充满粗犷的男性魅力，但那双清澈的眼晴，却又是那麽秀逸。他鼻子
挺直，象征坚强、决断的铁石心肠，他那薄薄的，嘴角上翘的嘴，看来也有些冷酷，但
只要他一笑起来，坚强就变作温柔，冷酷也变作同情，就像是温暖的春风吹过了大地。
");
    set("attitude","friendly");
    set("per", 40);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.luori" :),
            }) );

    set("combat_exp", 10000000);
    set("score", 50000);

    set_skill("force", 150);
    set_skill("bibo-force", 150);
    set_skill("unarmed", 120);
    set_skill("dodge", 320);
    set_skill("luoriquan", 200);
    set_skill("move", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 150);
    set_skill("literate",150);
    set_skill("stealing",320);
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("move"  , "fengyu-piaoxiang");
    setup();
}

void init()
{
	::init();
	add_action("do_look","look");
}
int do_look(string arg)
{
    object me;
    me = this_player();
    
    if( (string)me->query("gender") == "女性" && 
        (arg == "nakedman chu"))
    {
        message_vision("$N一颗芳心砰砰的跳的飞快．．．．\n"NOR, me);
        me->unconcious();
        return 1;
    }
    else return 0;
}

