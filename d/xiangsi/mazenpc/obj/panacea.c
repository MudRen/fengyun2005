#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("万应灵丹",({"panacea"}));
  	set("long", "一粒功能救身保命的万应灵丹，据说可令人进入假死状态逃脱险境。\n");
  	set("desc_ext","服用（eat panacea）");
  	set("base_value",10000);
  	set("unit","堆");
  	set("base_unit","粒");
  	set("base_weight",10000);
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({"eat" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "panacea")
		return 0;
		
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
  	message_vision(CYN"$N手忙脚乱的将万应灵丹望嘴里塞去。\n"NOR,me);
	if (me->is_fighting())
	{
		if (me->query("timer/jiasi") + 1800 <= time())	// 30分钟一次
		{
			me->set("timer/jiasi",time());
			tell_object(me,MAG"药一下肚，你只觉得腹中如同刀搅，痛不可当。\n");
			message_vision(RED"$N的脸突然诡异地扭曲，四肢开始猛烈抽搐。\n"RED"一丝黑色的鲜血从$N口鼻中渗了出来．．．\n"NOR"\n",me);
			me->remove_all_killer();
			me->remove_all_enemy();
			me->set("eff_kee",1);
			me->set("kee",1);
				buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"curse",
				"name":"皓月天宫·万应灵丹",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":NOR CYN " <倒地不起>" NOR,
				"time":300,	// 用药假死，时间极长。
				"buff_msg":"$N死了。\n"NOR,
				"disa_msg":CYN"\n\n$N在地上挣扎了两下，勉力爬了起来。\n"NOR,
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
			me->add_temp("block_msg/all",-1);
			tell_object(me,HIY"\n【传闻】"+me->query("name")+"("+me->query("id")+")莫名其妙地死了。\n"NOR);
			tell_object(me,"\n鬼门关 - \n    猛一惊醒，不觉身在鬼门关，高大的城墙边渭水环绕，阴气森森，几个面目狰\n狞的牛头，马面手持武器把守城门，勾死人手持铁链正在拖拽着几个人影走了进去\n．．．．．．．，城门楼上高悬一幅牌匾：\n\n\n"RED"                        鬼门关"NOR);
			tell_object(me,"\n\n    这里明显的出口是 "HIG"south"NOR" 和 "HIG"east"NOR"。"HIW"\n  铁索 牛头"NOR"(Niutou)\n"HIW"  枷铐 马面"NOR"(Mamian)\n");
			tell_object(me,"  朱笔判官(Panguan)\n\n判官喝道：牛头，马面何在？\n\n"HIW"判官那锐利的目光象把刀一样在你身上扫来扫去。\n\n"HIR"你的眼前一黑，接著什麽也不知道了....\n\n"NOR);
			me->add_temp("block_msg/all",1);
		}
	}
  	add_amount(-1);
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
