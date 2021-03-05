#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("沙曼", ({ "sha man","shaman" }) );
        set("gender", "女性" );
        set("title", CYN "漂泊四海"NOR);
        set("age", 32);
        set("per", 30);
        set("price_modifier",1000000);
        set("long", "她也许太高了些，可是修长的身材线条柔和，全身都散发着一种无法抗拒的魅
力，脸部的轮廊明显，一双猫一般的眼睛里动着海水般的碧光，显得冷酷而聪明，
却又带着种说不出的懒散之意，对生命仿佛久已厌倦。\n");
        set("combat_exp", 350000);
        set("chat_chance", 1);
        set("vendor_goods", ([
BOOKS"class/cloud-dance_yegui_1":      20,
BOOKS"class/cloud-dance_yegui_2":      20,
BOOKS"class/cloud-dance_yegui_3":      20,
BOOKS"class/dragonstrike_zjbl_2":      20,
BOOKS"class/dragonstrike_zjbl_3":      20,
BOOKS"class/dragonstrike_zjbl_4":      20,
BOOKS"class/dream-herb_huanmengluo_2":      20,
BOOKS"class/dream-herb_huanmengluo_3":      20,
BOOKS"class/essencemagic_team_drift_1":      20,
BOOKS"class/gouyee_heal_2":      20,
BOOKS"class/gouyee_heal_3":      20,
BOOKS"class/iceheart_buffup_2":      20,
BOOKS"class/iceheart_buffup_3":      20,
BOOKS"class/iceheart_buffup_4":      20,
BOOKS"class/kwan-yin-spells_ma_2":      20,
BOOKS"class/fengmo-staff_fengmo":      20,
BOOKS"class/nine-moon-claw_weiwoduzun_2":      20,
BOOKS"class/nine-moon-claw_weiwoduzun_3":      20,
BOOKS"class/qidaoforce_juxue_2":      20,
BOOKS"class/qidaoforce_juxue_3":      20,
BOOKS"class/xueyeqianzong_feline_2":      20,
BOOKS"class/xueyeqianzong_feline_3":      20,
BOOKS"class/xueyeqianzong_wolverine_3":      20,
BOOKS"class/xuezhan-spear_liguang_2":      20,
BOOKS"class/xuezhan-spear_liguang_3":      20,
// BOOKS"class/xuezhan-spear_liguang_4":      20,	
BOOKS"class/yijinjing_shield_2":      20,
BOOKS"class/yijinjing_shield_3":      20,
BOOKS"class/yue-spear_juechufengsheng_2":      20,
BOOKS"class/yue-spear_juechufengsheng_3":      20,
BOOKS"learn/iron-cloth_75":				20,
BOOKS"learn/magic_60":					20,
BOOKS"learn/spells_100":				20,
		]) );
        set("attitude", "friendly");
        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("zhaixin-claw",70);
        set_skill("cloud-dance",80);
        set_skill("parry",90);
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","cloud-dance");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{       
        object ob;

        ::init();
		add_action("do_vendor_list", "list");
}
