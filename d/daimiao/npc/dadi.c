inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name(HIY"东岳大帝"NOR, ({ "master dadi", "master", "dadi" }) );

    set("gender", "男性");
    set("age", 99);
    set("long", "东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n");
    set("attitude", "peaceful");
    set("str", 2600);
    set("force", 40000);
    set("max_force", 80000);
    set("force_factor", 1000);
    set("combat_exp", 10000000);
    set("score", 200000);
    set_skill("unarmed", 120);
    set_skill("force", 100);
    set_skill("iron-cloth", 100);
    set_skill("yiqiforce", 60);
    set_skill("literate",100);
    set_skill("incarnation",320);
    set_skill("dodge",100);
    set_temp("apply/attack",300);
    set_temp("apply/damage",30000);
    map_skill("iron-cloth", "yiqiforce");
    map_skill("force", "yiqiforce");
    map_skill("unarmed", "yiqiforce");
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("东岳派", 1, "祖师");
    set("ranks",({"地仙","人仙","天仙","大罗金仙"}));
    set("rank_levels",({320000,5187000,26244000}));
    setup();
}
int accept_fight(object me)
{
    return 0;
}

void init()
{
    add_action("do_look","look");
}

int do_look(string arg)
{
    if (arg == "master dadi" || arg == "dadi" || arg =="master")
    {
        write("东岳大帝高六尺，型貌活灵活现，宛如真人一般。\n");
        return 1;
    }
    return 0;
}

