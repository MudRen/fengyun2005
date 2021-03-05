// garrison.c

#include <ansi.h>

inherit NPC;
void create()
{
    set_name("狱卒长", ({ "yuzu zhang", "yu zu zhang" }) );
    set("long","济南大牢的狱卒长，放不放人都在于他的一句话。\n");
    set("attitude", "heroism");
    set("combat_exp", 1000000);
    
    set("chat_chance", 1);
    set("chat_msg", ({
		"狱卒长低声道：“这点响银，还不够老子打酒喝。”\n",
    }) );
    setup();

    carry_object("/obj/armor/cloth")->wear();
}

void destory_this()
{
	message_vision("$N不耐烦道：“还没想好吗？那就慢慢想吧！想好了再叫我。”\n",this_object());
	message_vision("$N悻悻然拂袖而去。 \n",this_object());
	destruct(this_object());
	return;
}

void release_player(object player)
{
	message_vision("$N说：“想出去？嘿嘿。。。\n",this_object());
	message_vision("$N看看左右没人，低声对$n说道：”有钱就可以放你出去，你付得起吗？“ \n",this_object(),player);
	message_vision("$N做了一个手势，低声道：”这个数，黄金50两。我直接从你帐户上转，愿不愿意？
	(ACCEPT YES/NO)”  \n",this_object());
	add_action("do_accept","accept");
	call_out("destory_this",20);
}

int do_accept(string arg)
{
	object player, room;
	int amount;
	player = this_player();
	remove_call_out("destory_this");
	if (arg == "yes")
	{
		amount = player->query("deposit");
		if (amount < 500000)
		{
			message_vision("$N气急败坏对$n大骂：“我查过了，你这个穷鬼根本没那么多钱！敢耍我，给我干活去吧！” \n",this_object(),player);
			message_vision("$N悻悻然拂袖而去。 \n",this_object());
			message_vision("$N被几个如狼似虎的狱卒押走了。\n",player);
			if (!room= find_object(AREA_JINAN"pyard"))
				room=load_object(AREA_JINAN"pyard");
			player->move(room);
			destruct(this_object());
		}else
		{
			amount = amount - 500000;
			player->set("deposit",amount);
			message_vision("$N带着讨好的笑对$n说：“我就说这位"+ RANK_D->query_respect(player) + "是聪明人！跟我走。”\n",this_object(),player);
			message_vision("$N将$n提出了牢房。 \n",this_object(),player);
			player->set("vendetta/authority", 0);
			player->delete("marks/crime");
			player->move("/d/jinan/dayu");
			player->set("startroom",AREA_FY"fqkhotel");
			message_vision("$N满心伤痕的出了牢房。 \n",player);
			destruct(this_object());
		}
		return 1;
	}
	if (arg == "no")
	{
		message_vision("$N冷哼道：“真是要钱不要命的家伙，看你能在这儿撑到几时。” \n",this_object(),player);
		message_vision("$N叫道：来呀，把这家伙拖到院子里去干活！\n",this_object(),player);
		message_vision("$N悻悻然拂袖而去。 \n",this_object());
		message_vision("$N被几个如狼似虎的狱卒押走了。\n",player);
		if (!room= find_object(AREA_JINAN"pyard"))
			room=load_object(AREA_JINAN"pyard");
			player->move(room);
		destruct(this_object());
		return 1;
	}
	return notify_fail("你只可ACCEPT YES OR NO \n");
}


