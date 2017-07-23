<!DOCTYPE html>

<html>
<body>

<form action="entropy.jsp" method="post">
Input string: <input type="text" name="input_string">
<input type="submit" value="Get String Entropy">
</form>

<%@page import="java.util.HashMap"%>

<%
	String input_string = request.getParameter("input_string");

	String output_string = "";

	if(input_string != null && !input_string.isEmpty()) 
	{
		float entropy = 0.0f;

		HashMap<Character, Integer> char_map = new HashMap<Character, Integer>();

		int len = input_string.length();

		for(int i = 0; i < len; i++) 
		{
			char c = input_string.charAt(i);

			Integer value = char_map.get(new Character(c));

			if(value == null)
				char_map.put(c, 1);
			else
				char_map.put(c, value + 1);
		}

		output_string = "<br>String: \"" + input_string + "\"<br>";
		output_string += "String length: " + len + "<br><br>";

		for(HashMap.Entry entry : char_map.entrySet()) 
		{
			float probability = (Integer) entry.getValue() / (float) len;

			output_string += "Character: \'" + entry.getKey() + "\'" + ", Count: " + entry.getValue() + ", Probability: " + probability + "<br>"; 

			entropy += probability * Math.log(probability);
		}

		if(entropy != 0.0)
			entropy = -entropy;

		output_string += "<br>Entropy: " + entropy + "<br>";
	}
%>

<%=output_string%>




</body>
</html>