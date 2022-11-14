package Utils;

import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class AES extends Log {
	static SecretKey key;
	static IvParameterSpec iv;
	static String algorithm;

	static {
		String keyString = "Us3rS3CR3TD4T4SS";
		String ivString = "tx7usNfRXTOf1Bs4lb5ldw==";
		algorithm = "AES/CBC/PKCS5Padding";

		byte[] decodedKey = keyString.getBytes();
		key = new SecretKeySpec(decodedKey, 0, decodedKey.length, "AES");

		byte[] decodedIv = Base64.getDecoder().decode(ivString);
		iv = new IvParameterSpec(decodedIv);
	}

	public static String encrypt(String input) {

		Cipher cipher = null;
		byte[] cipherText = null;
		try {
			cipher = Cipher.getInstance(algorithm);
			cipher.init(Cipher.ENCRYPT_MODE, key, iv);
			cipherText = cipher.doFinal(input.getBytes());
		} catch (NoSuchAlgorithmException | NoSuchPaddingException | IllegalBlockSizeException | BadPaddingException
				| InvalidKeyException | InvalidAlgorithmParameterException e) {
			e.printStackTrace();
		}
		return Base64.getEncoder().encodeToString(cipherText);
	}

	public static String decrypt(String cipherText) {

		Cipher cipher = null;
		byte[] plainText = null;
		try {
			cipher = Cipher.getInstance(algorithm);
			cipher.init(Cipher.DECRYPT_MODE, key, iv);
			plainText = cipher.doFinal(Base64.getDecoder().decode(cipherText));
		} catch (IllegalBlockSizeException | BadPaddingException | InvalidKeyException
				| InvalidAlgorithmParameterException | NoSuchAlgorithmException | NoSuchPaddingException e) {
			e.printStackTrace();
		}
		return new String(plainText);
	}

}
