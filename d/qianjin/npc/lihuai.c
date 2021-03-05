inherit NPC;
#include <ansi.h>
void create()
{
        object weapon;
        set_name("李坏", ({ "li huai","li" }) );
        set("gender", "男性" );
                set("nickname",HIG"又见飞刀"NOR);
                set("age",20);
        set("reward_npc", 1);
                set("difficulty", 10);
                set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 1);
        set("long","一个风尘仆仆的少年人，穿一身灰扑扑的衣裳，\n看起来本应该无比落魄，可是却又无比精神。\n");
        create_family("风云一刀", 4, "人杰");
        set("combat_exp", 10000000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "李坏道：李善？我的名字应该叫李善？像我这么样的人，就算姓李，也应该叫李坏。\n",
                "李坏笑道：名字叫李坏的人，并不一定真的就是坏人。\n",
                "李坏看了你一眼，突然抬手吃了几口"YEL"豆腐"NOR"。\n",
                "李坏的眼神突然变得虚无缥缈，悠悠的叹道：你真的就这么样走了？真的．．．\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
                set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
        map_skill("throwing", "feidao");
        setup();
        weapon = carry_object("/obj/armor/cloth");
                weapon->set("name",HIR BLK"灰扑扑的衣裳"NOR);
                weapon->wear();
        weapon=carry_object("/questnpc/obj/leaf");
        weapon->set_name(YEL"豆腐"NOR, ({ "tofu" }) );
                weapon->set("long","一块嫩嫩滑滑的豆腐，你实在不敢相信这也是一种武器！\n");
                weapon->set("base_unit","块");
                weapon->set("value",0);
                weapon->set_amount(200);
                weapon->set("volumn",200);
                weapon->wield();
}

int do_look(string arg)
{
        if (!arg)
                return 0;
        if (present(arg,environment()) != this_object())
                return 0;
        write("一个风尘仆仆的少年人，穿一身灰扑扑的衣裳，\n看起来本应该无比落魄，可是却又无比精神。\n他看起来约二十多岁。\n他风度翩翩，如玉树临风。\n他"CYN"让人觉得气质文弱"GRN"，武功看起来好象"HIB"初窥门径"NOR"，出手似乎极轻。\n他"HIG"看来身上并无丝毫伤痕。"NOR"\n他右手捏着一块"YEL"豆腐"NOR"(Tofu)\n  身穿"HIR BLK"灰扑扑的衣裳"NOR"(Cloth)\n");
        return 1;
}

void init()
{
        add_action("do_look","look");
        ::init();
} 


object select_opponent()        
{
        object * enemy;
        int i;
        enemy = query_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        clean_up_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        for(i=0; i<sizeof(enemy); i++)
                if (userp(enemy[i]) && enemy[i]->query("annie/moon_master") != 4)
                        return enemy[i]; // focus user. ; annie 6.25.03
        
        return enemy[random(sizeof(enemy))];
}

void heart_beat()
{
        object feidao;
        object target;
        if(is_fighting())
        {
                target = select_opponent();
                        message_vision(CYN"\n李坏打了一个哈欠，觉得无聊极了。\n\n"NOR,this_object());
                        feidao = new(AREA_FY"npc/obj/xlfd_knife");
                        feidao->move(this_object());
                        command("unwield deadleaf");
                        command("wield flying blade");
                        target->set_temp("last_damage_from",this_object());
                        (CLASS_D("npc") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
                        feidao->throw_weapon(this_object(),target,0);
                        if (feidao)
                        {
                                feidao->unwield();
                                feidao->move(load_object("/obj/void"));
                                reset_action();
                        }
                        command("wield deadleaf");
                        command("hehe");
                return ::heart_beat();
        }
        else
                return ::heart_beat();
}


int accept_object(object me, object obj)
{
        if (obj->query("name") == "小纸袋" && obj->query("real") == 3)
        {
                if (REWARD_D->riddle_check(me,"两世恩怨") == 9 )
                {
                        message_vision(CYN"李坏打开小纸袋，嗅了嗅其中的粉末。\n"NOR,me);
                        message_vision(CYN"李坏默然半晌，低声叹了口气。\n"NOR,me);
                        ccommand("say 这样啊……");
                        ccommand("sigh");
                        ccommand("emote 点了点头道：既是如此，就让李坏一败，以作偿当年李家欠薛家的冤怨。");
                        ccommand("say 请回去告诉素素吧，在下次明月盈空的时候，我在老地方等她。");
                       	REWARD_D->riddle_set(me,"两世恩怨",10);

                        message_vision(CYN"李坏慢慢的走回废园中。\n"NOR,me);
                        move(load_object("/d/wiz/deathroom"));
                        return 1;
                }
        }
        command("smile");
        command("say 多谢，多谢！");
        return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

