// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("马秀真", ({ "ma xiuzhen","ma" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIC"三英四秀之"NOR );
        set("long","身材很高，细细长长的一双凤眼，在笑的时候仿佛也带着种逼人的杀气。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("combat_exp", 200000);
        
        set("inquiry",  ([
                "叶孤城" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                "master ye" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                  "西门吹雪" :" 这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
                  "master ximen" : "这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
        ])                      );
        
        set("chat_chance", 1);
        set("chat_msg", ({
            "马秀真挑了挑丹凤眼，不屑道：白云岛也不过如此。\n",
        }) );

		auto_npc_setup("wang",70,100,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);        
        delete_skill("spring-watter");
        delete_skill("iron-cloth");
        setup();

        carry_object(__DIR__"obj/emeisword1")->wield();
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}
