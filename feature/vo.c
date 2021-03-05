// save.c
inherit F_SAVE;
string query_save_file()
{
	string* str1;			
	str1=explode(base_name(this_object()),"/");
	return sprintf(DATA_DIR "vo/%s/%s",str1[1],str1[2]);
}

int restore_me(string file)
{
	return restore_object(file);
}
