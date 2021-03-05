// flowerowner.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu for flower delivery Oct/29/2001

#include <ansi.h>
#include <dbase.h>

string *delivery_list = ({			// 10k - 20k
	"李寻欢:/d/quicksand/npc/bu_waiter:风云西城外丰号布铺",
	"陆小凤:/d/fy/npc/leng:风云西城银钩赌坊内",
	"陆小凤:/d/fy/npc/fangyufei:风云西城银钩赌坊内",
	"花街大少:/d/fy/npc/bookgirl:风云城内风云阁楼上",
	"楚留香:/d/jinan/npc/songtian:济南趵突泉",
	"楚留香:/d/jinan/npc/surong:济南大明湖",
	"阿青:/d/laowu/npc/alone:老屋阿龙铁匠铺",
	"花街大少:/d/laowu/npc/dang:老屋不醉无归小酒家",
	"寒梅先生:/d/laowu/npc/leng:老屋草药店",
	"花姑:/d/chenxiang/npc/omonk:沉香镇城隍庙",
	"钟旒秀:/d/chenxiang/npc/medman:沉香镇的中药店",
	"花姑:/d/guanwai/npc/waiter:关外大昭寺迎梅客栈",
	"小方:/d/guanwai/npc/sunshine:关外草原红羽之帐",
	"小方:/d/guanwai/npc/qi:关外大昭寺穹形石窟",		
	"花满城:/d/wudang/npc/dahanwife:武当山脚下农家",
	"花满城:/d/wudang/npc/oldwoman:武当山脚下农家厨房",
	
});

string *delivery_list_2 = ({			// 20k - 40k
	"诸葛小雷:/d/fugui/npc/tianxin:富贵山庄青石路附近",
	"姬冰燕:/d/fugui/npc/clothlady:富贵山庄青石小街附近",
	"俊俏相公:/d/fugui/npc/beauty:富贵山庄山间小路附近",
	"胡铁花:/d/huashan/npc/jin:华山青砖甬道",
	"丁枫:/d/huashan/npc/linger:华山别院",
	"胡铁花:/d/huashan/npc/gao:华山苍龙岭",
	"花满城:/d/baiyun/npc/fishwoman:南海沙滩",
	"花满城:/d/baiyun/npc/niuroutang:南海狐狸窝",
	"花满城:/d/baiyun/npc/hockowner:南海狐记当铺",
	"花满城:/d/chuenyu/npc/cleangirl:黑松山东厅",
	"花满城:/d/qingping/npc/laner:清平山庄小厅",
	"花满城:/d/qingping/npc/yan:清平山庄后花园",
	"花满城:/d/qianjin/npc/chick2:千金楼",
	"花满城:/d/qianjin/npc/chick1:千金楼",
	"花满城:/d/taoyuan/npc/singgirl:桃源村小茶栈",
	"花满城:/d/taoyuan/npc/caier:桃源村渔家",
	"花满城:/d/shenshui/npc/shui_tianji:东海木屋内",
	"花满城:/d/taoguan/npc/watcher_taoist:三清山",
	"花满城:/d/taoguan/npc/jing2:三清山",
});

string *delivery_list_3 = ({		//40k - 60k
	"方玉飞:/d/fy/npc/fangyuxiang:风云西城银钩赌坊暗道内",
	"中原一点红:/d/guanyin/npc/qu:天枫山庄花海附近",
	"展梦白:/d/palace/npc/feiyu:帝王谷山阁附近",
	"花飞:/d/palace/npc/manfeng:帝王谷书房附近",
	"萧十一郎:/d/taishan/npc/shenbijun:泰山踏莎斋",
	"花满城:/d/taishan/npc/lengqingshuang:泰山凌汉峰",
	"萧十一郎:/d/huangshan/npc/feng:黄山慈光阁",
	"太白逸:/d/huangshan/npc/yan:黄山石笋杠",
	"萧十一郎:/d/huangshan/npc/bing:黄山天都峰",
	"花满城:/d/loulan/npc/bai:古城楼兰的石牢",
	"花满城:/d/loulan/npc/se:古城楼兰南佛塔",
	"花满城:/d/wolfmount/npc/xiaoling:狼山的浣花溪",
	"花满城:/d/xiangsi/npc/suu:相思岭的霜笛清晓",
	
});

string *delivery_list_4 = ({		//60k - 200k
	"陆小凤:/d/ghost/npc/yeling:幽灵山庄",
	"花满城:/d/eren/npc/pinggu:恶人谷",
	"花满城:/d/eren/npc/xiaojiao:恶人谷",
	"花满城:/d/zangbei/npc/gao:藏北高原的快活林",
	"花满城:/d/zangbei/npc/xiaodie2:藏北高原小河畔",
	"花满城:/d/zangbei/npc/dawa:藏北草原帐篷里",
	"花满城:/d/zangbei/npc/girl:边城河滩",
	"花满城:/d/biancheng/npc/girl:边城销金窟",
	"花满城:/d/wolfmount/npc/yaomei:狼山的狼窝",
	"花满城:/d/tieflag/npc/maggirl:大旗谷",
	"花满城:/d/tieflag/npc/shui:大旗谷",
	"花满城:/d/cyan/npc/man:明霞岭",
	"花满城:/d/cyan/npc/zhuxiang:明霞岭",
	"花满城:/d/baiyun/npc/beautyboss:白云岛",
	"花满城:/d/baiyun/npc/qianqian:白云岛",
	"花满城:/d/baiyun/npc/mixian:白云岛",
});

string *delivery_list_5 = ({		//500k - 650k
	"花满城:/d/qianjin/npc/funu:千金楼",
	"蒋旭旭:/d/bat/npc/tong1:蝙蝠岛",
	"陶宝宝:/d/bat/npc/tong2:蝙蝠岛",
	"王小小:/d/bat/npc/tong3:蝙蝠岛",
	"张咪咪:/d/bat/npc/tong4:蝙蝠岛",
	"花满城:/d/wolfmount/npc/yaomei:狼山的狼窝",
	"花满城:/d/shenshui/npc/needlegirl2:神水宫",
	"花满城:/d/shenshui/npc/qinggirl:神水宫",
	"花满城:/d/tieflag/npc/qinggirl2:长春岛",
	"花满城:/d/tieflag/npc/qinggirl1:长春岛",
	"花满城:/d/xiangsi/npc/seablue:相思岭",
	"花满城:/d/xiangsi/npc/leng2:相思岭",
	
});

string wait_period(int timep);

string get_flower()
{
	//get flower from the vendor list
	int i;
	mapping goods;
	string *names;
	if( !mapp(goods = query("vendor_goods")) ) 	return "";
	names = keys(goods);
	if (!sizeof(names))
	{
		//should we give out a default flower or don't let them deliver?
		return "";		// no more delivery
	}
	i = sizeof(names);
	return names[random(i)];
}

mapping query_delivery(object who)
{
	int i,exp;
	string *delivery,name;
	string *pick_list;
	object *ob,ob1;
	
	ob = users();
	
	ob1 = ob[random(sizeof(ob))];
	
	if (wizardp(ob1))	ob1 = ob[random(sizeof(ob))];
	if (wizardp(ob1))	ob1 = ob[random(sizeof(ob))];
	
	name = ob1->query("name");
	if (!name || wizardp(ob1))	name = "李寻欢";
		
	exp = who->query("combat_exp")/1000;
	if (exp<=20)	pick_list=delivery_list;
	else if (exp<=40)	pick_list = delivery_list_2;
	else if (exp<=60) 	pick_list = delivery_list_3;
	else if (exp<=200)	pick_list = delivery_list_4;
	else 				pick_list = delivery_list_5;
			
	i = sizeof(pick_list);
	delivery = explode(pick_list[random(i)],":");
	return (["sender": name,
			"receiver": delivery[1],
			"area":		delivery[2],
			]);
}

// CHecking Lists
void test_list(){

	string *pick;
	string *data;
	int i;
	object ob;
	
	pick = delivery_list_5;
	for (i=0;i<sizeof(pick);i++){
		data = explode(pick[i],":");
		if (objectp(ob=new(data[1]))){
			CHANNEL_D->do_sys_channel("sys", sprintf("%O\n",ob) );
			destruct(ob);
		}	else
			CHANNEL_D->do_sys_channel("sys","error = "+ data[1]+"\n");
	}	
			
}

int assign_delivery()
{
	mapping delivery;
    	string dstr;
	object who,flower,silver;
    	who = this_player();
	
/*	if (who->query("combat_exp") >= 10000 )
	{
		message_vision("$N诚惶诚恐对$n道：“怎么敢劳您大驾”！\n",this_object(),who );
		return 1;
	}
	
	if (who->query("KILLED") >= 20 )
	{
		message_vision("$N沉吟了一会儿道：“"+RANK_D->query_respect(who)+"小小年纪，怎么印堂发黑？“\n",this_object(),who );
		message_vision("$N摇摇头说：“不吉，不吉，这送花的事你不适合干。“\n",this_object());
		return 1;
	}*/
	
	 
	if(who->is_ghost() || who->is_zombie()) {
		tell_object(who,this_object()->name()+"道：“我该不是见鬼了吧？”\n");
		return 1;
	}

	if((delivery =  who->query("delivery")) && (time() - who->query("delivery_time") <= 600)) {
		return 0;
	}
	
	//delivery unfinished and back to ask again in 10 mins
	if ((delivery =  who->query("delivery")) && (time() - who->query("delivery_time"))<= 1200)
	{
		tell_object(who,HIW"你要过" 
				+  QUESTS_D->wait_period(1200-time()+who->query("delivery_time")) 
				+ "之后才可继续送花。\n"NOR);
		return 1;
	}
	//delivery cancled by player
	if ((!delivery =  who->query("delivery")) && ((who->query("next_delivery_time")) > time()))
	{
		tell_object(who,HIW"你要过" 
				+  QUESTS_D->wait_period(who->query("next_delivery_time") - time()) 
				+ "之后才可继续送花。\n"NOR);
		return 1;
	}
/*
	silver=present("silver_money", who);
	if(!silver) 
	{
		tell_object(who,"你身上没有足够的银子付定金呀。\n");
		return 1;
	}
	if (silver->query_amount()<1)
	{
		tell_object(who,"你身上没有足够的银子付定金呀。\n");
		return 1;
	}
	silver->add_amount(-1);
*/

	if (who->query("deposit") < 100) {
		tell_object(who,"你银行里的存款不够1两银子。\n");
		return 1;
	}
	who->add("deposit",-100);
	
	delivery = query_delivery(who);
	flower = new(get_flower());
	if (!flower) {
		message_vision("$N摇摇头说：“这里的花都送光了。“\n",this_object());
		return 1;
	}

	//flower->set("sender",delivery["sender"]);
	//flower->set("receiver",delivery["receiver"]);
	flower->set("delivery",delivery);
	flower->wither();
	if (flower->move(who))
	{
		who->set("delivery", delivery);
		flower->set("delivery_time", (int)time());	
		who->set("delivery_time", (int)time());	
		dstr = WHT"“这是" + delivery["sender"] + "送给住在"+ delivery["area"]+"的"
+ delivery["receiver"]->name(1) + "的花。请速去速回。”\n"NOR;
		message_vision("$N小心翼翼递给$n一朵"+flower->name()+"道：\n" + dstr,this_object(),who);

	} else
		destruct(flower);
	return 1;
}

int cancel_delivery(string arg)
{
	object who;
	who = this_player();
	if (arg != "delivery" && arg != "送花")
	{
		return 0;
	}
	if(  who->query("delivery") && (time() - who->query("delivery_time") < 600))
	{
		who->delete("delivery");
		who->delete("delivery_time");
		tell_object(who, this_object()->name() + "说道：好吧，这个送花任务就算了吧．．\n");
		who->set("next_delivery_time", time() + random(120));
		return 1;
	}else if (!who->query("delivery"))
	{
		return notify_fail("你现在没有任何送花任务！\n");
	}else
	{
		return notify_fail("你已错过上一个任务。等下一个吧。\n");
	}
}

int give_deposit()
{
	int amount;
	object silver,me;
	me = this_player();
	amount = me->query("marks/delivery_success");
	if (amount>=1)
	{
/*		silver = new("/obj/money/silver");
		silver->set_amount(amount);
		message_vision("$N对$n道：“这是你的全部押金。”\n",this_object(),me);
		silver->move(me);*/
		
		me->add("deposit",100* amount);
		tell_object(me, this_object()->name()+"对你说：你的押金（"+amount+"两银子）已经全部转入你的银行账号了。\n");
		
		me->set("marks/delivery_success",0);
		return 1;
	}
	message_vision("$N对$n道：“你并没有押金在这儿。”\n",this_object(),me);
	return 1;

}

/*

the code which player place reservation
not in use right now
int book_flowers(string arg)
{
	string starget,sflower;
	object target,flower,who;
	mapping goods,userdelivery;
	string *names,flowerlist;
	who = this_player();
	flowerlist = "";
	if (!arg || sscanf(arg, "%s %s", starget,sflower) != 2 ) 
	{
		return notify_fail("命令格式:book 玩家ID 花的ID\n");
	}	
	if (sizeof(user_reservation_list)>=20)
	{
		return notify_fail("本店订单已满，不在接受新的订单。\n");
	}

	if (!target = find_player(starget))
	{
		return notify_fail("你只可预订花给在线玩家。\n");
	}
	if( mapp(goods = query("vendor_goods")) ) 
	{
		names = keys(goods);
		if (sizeof(names)) 
		{
			for (int i=0;i<sizeof(names);i++ )
			{

				flowerlist = flowerlist + names[i]->name() + "("+names[i]->query("id")+")"+"\n";
				if ( names[i]->query("id") == sflower )
				{
					userdelivery = (["sender": who->name(1),
						"receiver": target->query("id"),
						"flower":names[i],
					]);
					user_reservation_list = user_reservation_list + ({userdelivery});
					message_vision("$N预订了一支"+names[i]->name()+"给"+target->name(1)+"\n",who);
					return 1;
					
				}
			}
		}
	}

	if (flowerlist == "")
	{
		return notify_fail("这里的花都卖光了。\n");
	}
	tell_object(who,"你现在只可预订下列花：\n"+flowerlist);
	return 1;

}
*/
