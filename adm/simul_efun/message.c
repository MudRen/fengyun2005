// message.c
string sort_msg(string input)
{
#ifdef BINARY_SUPPORT
        return efun::sort_string(input, 60, 0);
#else
        int i;
        int sl;
        int len;
        int esc;
        string result;
        result = "";

        len = 0;
        esc = 0;
        sl = strlen(input);
        for( i = 0; i < sl; i++ ) {
                if( len >= 64 && input[i] != '\n' ) {
                        switch (input[i..i+1])
                        {
                        case "：":
                        case "”":
                        case "。":
                        case "，":
                        case "、":
                        case "；":
                        case "）":
                        case " )":
                        case "！":
                        case "？":
                                break;
                        default:
                                len = 0;
                                result += "\n";
                                break;
                        }
                }

                if( input[i] == 27)
                        esc = 1;

                if( !esc ) {
                        if( input[i] > 160 ) {
                                result += input[i..i+1];
                                i ++;
                                len += 2;
                                continue;
                        }
                        if( input[i] == '\n' ) {
                                result += "\n";
                                len = 0;
                                continue;
                        }
                }

                result += input[i..i];
                if( !esc ) len++;

                if( esc && input[i] == 'm' )
                        esc = 0;
        }

        if( i < sl )
                result += input[i..sl-1];

        return result;
#endif
}
varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;
	object room;
	string *v_room;
	int i;

	my_name= me->name();
	my_gender = me->query("gender");
		
	if (you && you == me)
	{
		str1 = replace_string(msg,"$p","$P");
		str1 = replace_string(str1,"$n","$N");
		str1 = replace_string(str1,  "$P", gender_self(my_gender));
		str1 = replace_string(str1, "$N", gender_self(my_gender));
	} else
	{	
		str1 = replace_string(msg,  "$P", gender_self(my_gender));
		str1 = replace_string(str1, "$N", gender_self(my_gender));
	}
	
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		if (you != me)
			message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	
	message("vision", str1, me);
	if(room=environment(me))
	{
		message("vision", str3,  environment(me), ({ me, you}) );
		if(v_room=room->query("viewer"))
		for(i=0;i<sizeof(v_room);i++)
			tell_room(v_room[i],str3);
	}
}

void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

varargs void message_sort(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;

        if( !objectp(me) || !environment(me) ) return;

        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ){
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                message("vision", sort_msg(str2), you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        message("vision", sort_msg(str1), me);
        message("vision", sort_msg(str3),  environment(me), ({ me, you}) );
}


varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}

void write(string str) {
	if(this_player()) {
		message("write", str, this_player());
	} else if(previous_object()) {
		message("write", str, previous_object());
	} else {
		efun::write(str);
	}
}

varargs void say(string str, mixed exclude)
{
	if(living(previous_object()))
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}

void notify_fail(mixed result) {
	string message;

	efun::notify_fail(result);

}
